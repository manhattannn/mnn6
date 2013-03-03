<?php

class MnnShow {
  public $link;               // string
  public $title;              // string
  public $day_of_week;        // integer
  public $category;           // string
  public $start;              // string
  public $end;                // string
  public $start_date;         // string
  public $end_date;           // string
  public $duration_actual;    // integer
  public $duration;           // integer
  public $is_current;         // boolean
  public $is_today;           // boolean
  public $is_primetime;       // boolean
  public $channel;            // string

  private $start_datetime;    // DateTime
  private $end_datetime;      // DateTime
  private $yc_weekday_start;  // DateTime
  private $yc_weekday_end;    // DateTime
  private $yc_weekend_start;  // DateTime
  private $yc_weekend_end;    // DateTime
  private $is_youthchannel;   // boolean

  /**
   * @param DateTime $start_datetime
   * @param integer $duration
   */
  function __construct($start_datetime, $duration, $is_youthchannel) {
    $this->yc_weekday_start = '15:00:00';
    $this->yc_weekday_end   = '17:00:00';
    $this->yc_weekend_start = '07:00:00';
    $this->yc_weekend_end   = '12:00:00';

    $this->start_datetime = $start_datetime;
    // watchdog('mnnshow', '6 $start_datetime: '.var_export($start_datetime, true), array(), WATCHDOG_INFO);
    // watchdog('mnnshow', '7 $duration: '.var_export($duration, true), array(), WATCHDOG_INFO);
    $this->duration_actual = round($duration / 30) * 30; // round to nearest 15 minutes
    $this->duration = $this->duration_actual;
    // watchdog('mnnshow', '8 $this->duration: '.var_export($this->duration, true), array(), WATCHDOG_INFO);
    $this->is_youthchannel = $is_youthchannel;

    $this->setTimeProperties();
  }

  public function setLink($link) {
    $this->link = $link;
  }

  public function setTitle($title) {
    $this->title = $title;
  }

  public function setCategory($category) {
    $this->category = $category;
  }

  public function setChannel($channel) {
    $this->channel = $channel;
  }

  /**
   * @return DateTime
   */
  public function getStartDatetime() {
    return $this->start_datetime;
  }

  /**
   * @return DateTime
   */
  public function getEndDatetime() {
    return $this->end_datetime;
  }

  private function setTimeProperties() {
    $this->end_datetime = clone $this->start_datetime;
    $this->end_datetime->add(new DateInterval('PT'.$this->duration.'M'));

    $this->start = $this->start_datetime->format('H-i');
    $this->end = $this->end_datetime->format('H-i');
    $this->start_date = $this->start_datetime->format('Y/m/d H:i');
    $this->end_date = $this->end_datetime->format('Y/m/d H:i');

    // day_of_week (monday = 1, sunday = 7)
    $this->day_of_week = intval($this->start_datetime->format('w'));
    if ($this->day_of_week == 0)
      $this->day_of_week = 7;

    // is_today
    $today = new DateTime(NULL, new DateTimeZone('America/New_York'));
    if ($today->format('Y-m-d') == $this->start_datetime->format('Y-m-d'))
      $this->is_today = 'true';
    else
      $this->is_today = 'false';

    // is_current
    $now = new DateTime(NULL, new DateTimeZone('America/New_York'));
    if ($now >= $this->start_datetime && $now <= $this->end_datetime)
      $this->is_current = 'true';
    else
      $this->is_current = 'false';

    // is_primetime (primetime is 7pm to midnight)
    $primetime_start = new DateTime($this->start_datetime->format('m/d/Y 19:00:00'), new DateTimeZone('America/New_York'));
    $primetime_end = new DateTime($this->start_datetime->format('m/d/Y 23:59:59'), new DateTimeZone('America/New_York'));
    if (mnnshow_is_date_in_range($primetime_start, $primetime_end, $this->start_datetime)
        || mnnshow_is_date_in_range($primetime_start, $primetime_end, $this->end_datetime))
      $this->is_primetime = 'true';
    else
      $this->is_primetime = 'false';

    // adjust duration if start or end is outside of displayed time block
    if ($this->is_youthchannel) {
      if ($this->day_of_week < 6) { // is yc, & a weekday
        $start = new DateTime($this->start_datetime->format('m/d/Y '.$this->yc_weekday_start));
        $end = new DateTime($this->end_datetime->format('m/d/Y '.$this->yc_weekday_end));
        if ($this->start_datetime < $start){
          $diff = $start->diff($this->start_datetime);
          $this->duration -= intval($diff->format('%i'));
        }
        if ($this->end_datetime > $end){
          $diff = $this->end_datetime->diff($end);
          $this->duration -= intval($diff->format('%i'));
        }
      }
      else { // is yc, & a weekend
        $start = new DateTime($this->start_datetime->format('m/d/Y '.$this->yc_weekend_start));
        $end = new DateTime($this->end_datetime->format('m/d/Y '.$this->yc_weekend_end));
        if ($this->start_datetime < $start){
          $diff = $start->diff($this->start_datetime);
          $this->duration -= intval($diff->format('%i'));
        }
        if ($this->end_datetime > $end){
          // watchdog('mnnshow', '3 $this->end_datetime: '.var_export($this->end_datetime, true), array(), WATCHDOG_INFO);
          // watchdog('mnnshow', '4 $end: '.var_export($end, true), array(), WATCHDOG_INFO);
          $diff = $this->end_datetime->diff($end);
          // watchdog('mnnshow', '5 $diff: '.var_export($diff, true), array(), WATCHDOG_INFO);
          $this->duration -= intval($diff->format('%i'));
        }
      }
    }
    else {
    }
  }

}