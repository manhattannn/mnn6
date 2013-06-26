<?php
  // drupal_add_js('sites/all/libraries/highcharts/highcharts.js');

  foreach ($node->field_election_district_photos as $photo) {
    $media[] = '<div class="item">' . $photo['view'] . '</div>';
  }
  foreach ($node->field_election_district_videos as $video) {
    $media[] = '<div class="item">' . $video['view'] . '</div>';
  }

  // Chart data.
  $race_ethnicity_arr = explode(';', $node->field_election_race_ethnicity[0]['value']);
  $race_ethnicity_arr = array_filter($race_ethnicity_arr);
  for ($i = 0; $i < count($race_ethnicity_arr); $i++) {
    $race_ethnicity_arr[$i] = '[' . trim($race_ethnicity_arr[$i]) . ']';
  }
  $race_ethnicity = implode(',', $race_ethnicity_arr);
?>

<article class="election-district node <?php print $classes; ?>" id="node-<?php print $node->nid; ?>">

<div class="clearfix">
  <div class="map-neighborhood">
    <div class="map">
      <?php print $node->field_election_map[0]['view']; ?>
    </div>
    <div class="neighborhood">
      <strong>Neighborhoods:</strong><br>
      <?php print $node->field_election_neighborhoods[0]['view']; ?>
    </div>
  </div>
  <div class="photo-video">
    <?php print implode('', $media); ?>
  </div>
</div>

<h3>District Stats</h3>
<ul class="district-stats">
  <li>
    <label for="">District Population</label>
    <div class="stat"><?php print $node->field_election_district_populati[0]['view']; ?></div>
  </li>
  <li>
    <label for="">Median Income</label>
    <div class="stat"><?php print $node->field_election_median_income[0]['view']; ?></div>
  </li>
  <li>
    <label for="">Unemployment Rate</label>
    <div class="stat"><?php print $node->field_election_unemployment_rate[0]['view']; ?></div>
  </li>
</ul>
<div class="district-charts">
  <div id="race-ethnicity" class="chart"></div>
  <div id="housing"></div>
</div>

</article>

<script>

$jq(document).ready(function () {

  // Build the chart
  var chart = new Highcharts.Chart({
    chart: {
      renderTo: 'race-ethnicity',
      plotBackgroundColor: null,
      plotBorderWidth: null,
      plotShadow: false
    },
    title: {
      text: 'Race/Ethnicity',
      align: 'left',
      style: {
        fontWeight: 'bold',
        fontSize: '16px',
        fontFamily: 'Helvetica, Arial, sans-serif',
        color: '#25292b',
        x: 0
      }
    },
    tooltip: {
      headerFormat: '<strong>{point.key}</strong><br>',
      valueDecimals: 1,
      valueSuffix: '%',
      positioner: function(labelWidth, labelHeight, point) {
        return { x: point.plotX + 10, y: point.plotY - 20 }
      }
    },
    plotOptions: {
      pie: {
        allowPointSelect: true,
        cursor: 'pointer',
        dataLabels: {
          enabled: false
        },
        showInLegend: true
      }
    },
    legend: {
      align: 'right',
      verticalAlign: 'center',
      layout: 'vertical',
      x: 0,
      y: 50,
      itemStyle: {
        fontSize: '11px'
      },
      labelFormatter: function() {
        return this.name + ' ' + this.y + '%';
      }
    },
    series: [{
      type: 'pie',
      name: 'Race/Ethnicity',
      data: [<?php print $race_ethnicity;?>]
      // data: [
      //     ['Firefox',   45.0],
      //     ['IE',       26.8],
      //     {
      //         name: 'Chrome',
      //         y: 12.8,
      //         sliced: true,
      //         selected: true
      //     },
      //     ['Safari',    8.5],
      //     ['Opera',     6.2],
      //     ['Others',   0.7]
      // ]
    }]
  });
});
</script>
