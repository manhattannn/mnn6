<?php
  // Pie chart data.
  if ($node->field_show_pie_chart[0]['value'] == 1) {
    $pie_chart_arr = explode(';', $node->field_pie_chart_data[0]['value']);
    $pie_chart_arr = array_filter($pie_chart_arr);
    for ($i = 0; $i < count($pie_chart_arr); $i++) {
      $pie_chart_arr[$i] = '[' . trim($pie_chart_arr[$i]) . ']';
    }
    $pie_chart = implode(',', $pie_chart_arr);
  }

  // Bar chart data.
  if ($node->field_show_bar_chart[0]['value'] == 1) {
    $bar_chart_arr = explode(';', $node->field_bar_chart_data[0]['value']);
    $bar_chart_arr = array_filter($bar_chart_arr);
    for ($i = 0; $i < count($bar_chart_arr); $i++) {
      $item = explode(',', $bar_chart_arr[$i]);
      $bar_chart_labels[] = trim($item[0]);
      $bar_chart_data[] = trim($item[1]);
    }
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
  <div class="district-videos">
    <div class="video video--district-overview">
      <?php print $node->field_video_district_overview[0]['view']; ?>
    </div>
    <div class="video video--district-debate">
      <?php print $node->field_video_district_debate[0]['view']; ?>
    </div>
  </div>
</div>

<?php if (($node->field_show_stat_1[0]['value'] == 1) || ($node->field_show_stat_2[0]['value'] == 1) ||($node->field_show_stat_3[0]['value'] == 1) || ($node->field_show_pie_chart[0]['value'] == 1) || ($node->field_show_bar_chart[0]['value'] == 1)) : ?>
  <h3>District Stats</h3>
  <?php if (($node->field_show_stat_1[0]['value'] == 1) || ($node->field_show_stat_2[0]['value'] == 1) ||($node->field_show_stat_3[0]['value'] == 1)) : ?>
    <ul class="district-stats">
      <?php if ($node->field_show_stat_1[0]['value'] == 1) : ?>
        <li>
          <label for=""><?php print $node->field_stat_1_label[0]['view']; ?></label>
          <div class="stat"><?php print $node->field_stat_1_data[0]['view']; ?></div>
        </li>
      <?php endif; ?>
      <?php if ($node->field_show_stat_2[0]['value'] == 1) : ?>
        <li>
          <label for=""><?php print $node->field_stat_2_label[0]['view']; ?></label>
          <div class="stat"><?php print $node->field_stat_2_data[0]['view']; ?></div>
        </li>
      <?php endif; ?>
      <?php if ($node->field_show_stat_3[0]['value'] == 1) : ?>
        <li>
          <label for=""><?php print $node->field_stat_3_label[0]['view']; ?></label>
          <div class="stat"><?php print $node->field_stat_3_data[0]['view']; ?></div>
        </li>
      <?php endif; ?>
    </ul>
  <?php endif; ?>
  <?php if (($node->field_show_pie_chart[0]['value'] == 1) || ($node->field_show_bar_chart[0]['value'] == 1)) : ?>
    <div class="district-charts">
      <?php if ($node->field_show_pie_chart[0]['value'] == 1) : ?>
        <div id="pie-chart" class="chart"></div>
      <?php endif; ?>
      <?php if ($node->field_show_bar_chart[0]['value'] == 1) : ?>
        <div id="bar-chart" class="chart"></div>
      <?php endif; ?>
    </div>
  <?php endif; ?>
<?php endif; ?>

</article>

<script>

$jq(document).ready(function () {

  // Build the charts
  <?php if ($node->field_show_pie_chart[0]['value'] == 1) : ?>
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
  <?php endif; ?>
  <?php if ($node->field_show_bar_chart[0]['value'] == 1) : ?>
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
  <?php endif; ?>
});
</script>
