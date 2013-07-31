<?php
  // drupal_add_js('sites/all/libraries/highcharts/highcharts.js');

  foreach ($node->field_election_district_photos as $photo) {
    if (isset($photo['fid'])) {
      $media[] = '<div class="item">' . $photo['view'] . '</div>';
    }
  }
  foreach ($node->field_election_district_videos as $video) {
    if (isset($video['value'])) {
      $media[] = '<div class="item">' . $video['view'] . '</div>';
    }
  }

  // Pie chart data.
  $pie_chart_arr = explode(';', $node->field_pie_chart_data[0]['value']);
  $pie_chart_arr = array_filter($pie_chart_arr);
  for ($i = 0; $i < count($pie_chart_arr); $i++) {
    $pie_chart_arr[$i] = '[' . trim($pie_chart_arr[$i]) . ']';
  }
  $pie_chart = implode(',', $pie_chart_arr);

  // Bar chart data.
  $bar_chart_arr = explode(';', $node->field_bar_chart_data[0]['value']);
  $bar_chart_arr = array_filter($bar_chart_arr);
  for ($i = 0; $i < count($bar_chart_arr); $i++) {
    $bar_chart_labels[] = trim(explode(',', $bar_chart_arr[$i])[0]);
    $bar_chart_data[] = trim(explode(',', $bar_chart_arr[$i])[1]);
  }
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
  <div id="pie-chart" class="chart"></div>
  <div id="bar-chart" class="chart"></div>
</div>

</article>

<script>

$jq(document).ready(function () {

  // Build the charts
  var pieChart = new Highcharts.Chart({
    chart: {
      renderTo: 'pie-chart',
      plotBackgroundColor: null,
      plotBorderWidth: null,
      plotShadow: false,
      spacingLeft: 0,
      width: 420,
      height: 260
    },
    credits: {
      enabled: false
    },
    title: {
      text: "<?php print $node->field_pie_chart_title[0]['value'] ?>",
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
    colors: [
      '#17c3dc',
      '#67b921',
      '#fefc65',
      '#ffaf04',
      '#33be6c',
      '#007efe'
    ],
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
      name: "<?php print $node->field_pie_chart_title[0]['value'] ?>",
      data: [<?php print $pie_chart;?>]
    }]
  });
  var chart2 = new Highcharts.Chart({
    chart: {
      renderTo: 'bar-chart',
      type: 'column'
    },
    credits: {
      enabled: false
    },
    title: {
      text: "<?php print $node->field_bar_chart_title[0]['value'] ?>",
      align: 'left',
      style: {
        fontWeight: 'bold',
        fontSize: '16px',
        fontFamily: 'Helvetica, Arial, sans-serif',
        color: '#25292b',
        x: 0
      }
    },
    xAxis: {
      categories: [ <?php print implode(',', $bar_chart_labels); ?> ],
      <?php if (count($bar_chart_labels) > 3) : ?>
        labels: {
          rotation: -45,
          align: 'right',
          style: {
            fontSize: '13px',
            fontFamily: 'Helvetica, Arial, sans-serif',
            color: '#25292b',
          }
        }
      <?php else : ?>
        labels: {
          align: 'center',
          style: {
            fontSize: '13px',
            fontFamily: 'Helvetica, Arial, sans-serif',
            color: '#25292b',
          }
        }
      <?php endif; ?>
    },
    yAxis: {
      min: 0,
      title: {
        text: "<?php print $node->field_bar_chart_yaxis_label[0]['value']; ?>",
        style: {
          fontWeight: 'normal',
          fontSize: '13px',
          fontFamily: 'Helvetica, Arial, sans-serif',
          color: '#25292b',
        }
      }
    },
    tooltip: {
      headerFormat: '<strong>{point.key}</strong><br>',
      valueDecimals: 1
    },
    plotOptions: {
      series: {
        colorByPoint: true,
        colors: [
          '#005b25',
          '#67b921'
        ]
      }
    },
    // colors: [
    //   // '#005b25'
    //   '#67b921'
    // ],
    legend: {
      enabled: false
    },
    series: [{
      type: 'column',
      name: "<?php print $node->field_bar_chart_yaxis_label[0]['value']; ?>",
      data: [ <?php print implode(',', $bar_chart_data); ?> ],
      dataLabels: {
        enabled: true,
        rotation: -90,
        color: '#FFFFFF',
        align: 'right',
        x: 4,
        y: 10,
        style: {
          fontSize: '13px',
          fontFamily: 'Helvetica, Arial, sans-serif'
        }
      }
    }]
  });
});
</script>
