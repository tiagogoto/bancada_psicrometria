const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
  <head>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link href="https://use.fontawesome.com/releases/v5.7.2/css/all.css" rel="stylesheet">

    <style>
      html {
        font-family: Arial;
        display: inline-block;
        margin: 0px auto;
        text-align: center;
      }
      h1 { font-size: 2.0rem; }
      p { font-size: 2.0rem; }
      .units { font-size: 1.2rem; }
      .dht-labels{
        font-size: 1.5rem;
        vertical-align:middle;
        padding-bottom: 15px;
      }
    </style>
  </head>
  <body>
    <h1>Universidade Federal de Rondonopolis</h1>

    <h2>Bancada Psicrometrica</h2>

    <h3>Psicrometro</h3>

     <p>
      <span class="dht-labels">Temperatura de Bulbo Seco : </span> 
      <span id="ValorTemperatura3">0</span>
      <sup class="units">&deg;C</sup>
    </p>

    <p> 
      <span class="dht-labels">Temperatura de Bulbo Umido : </span> 
      <span id="ValorTemperatura4">0</span>
      <sup class="units">&deg;C</sup>
    </p>

    <h3>Dados do Ar</h3>

    <p>
      <span class="dht-labels">Temperatura do ar na entrada : </span> 
      <span id="ValorTemperatura1">0</span>
      <sup class="units">&deg;C</sup>
    </p>
     <p>
      <span class="dht-labels">Temperatura do ar na saida : </span> 
      <span id="ValorTemperatura2">0</span>
      <sup class="units">&deg;C</sup>
    </p>
    <p>
      <span class="dht-labels">Umidade do ar na entrada : </span>
      <span id="ValorUmidade1">0</span>
      <sup class="units">%</sup>
    </p>
    <p>
      <span class="dht-labels">Umidade do ar na saida : </span>
      <span id="ValorUmidade2">0</span>
      <sup class="units">%</sup>
    </p>

    <h3>Dados da Agua</h3>

    <p> 
      <span class="dht-labels">Temperatura da agua na entrada : </span> 
      <span id="ValorTemperatura5">0</span>
      <sup class="units">&deg;C</sup>
    </p>

    <p> 
      <span class="dht-labels">Temperatura da agua na saida : </span> 
      <span id="ValorTemperatura6">0</span>
      <sup class="units">&deg;C</sup>
    </p>
    
    <script>
      setInterval(function() {
        getTemperatureData1();
        getHumidityData1();
        getTemperatureData2();
        getHumidityData2();
        getTemperatureData3();
        getTemperatureData4();
        getTemperatureData5();
        getTemperatureData6();

      }, 2000); 

      function getTemperatureData1() {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
          if (this.readyState == 4 && this.status == 200) {
            document.getElementById("ValorTemperatura1").innerHTML =
            this.responseText;
          }
        };
        xhttp.open("GET", "readTemperature1", true);
        xhttp.send();
      }

      function getHumidityData1() {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
          if (this.readyState == 4 && this.status == 200) {
          document.getElementById("ValorUmidade1").innerHTML =
          this.responseText;
          }
        };
        xhttp.open("GET", "readHumidity1", true);
        xhttp.send();
      }

      function getTemperatureData2() {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
          if (this.readyState == 4 && this.status == 200) {
            document.getElementById("ValorTemperatura2").innerHTML =
            this.responseText;
          }
        };
        xhttp.open("GET", "readTemperature2", true);
        xhttp.send();
      }

      function getHumidityData2() {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
          if (this.readyState == 4 && this.status == 200) {
          document.getElementById("ValorUmidade2").innerHTML =
          this.responseText;
          }
        };
        xhttp.open("GET", "readHumidity2", true);
        xhttp.send();
      }

       function getTemperatureData3() {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
          if (this.readyState == 4 && this.status == 200) {
            document.getElementById("ValorTemperatura3").innerHTML =
            this.responseText;
          }
        };
        xhttp.open("GET", "temperaturec1", true);
        xhttp.send();
      }

      function getTemperatureData4() {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
          if (this.readyState == 4 && this.status == 200) {
            document.getElementById("ValorTemperatura4").innerHTML =
            this.responseText;
          }
        };
        xhttp.open("GET", "temperaturec2", true);
        xhttp.send();
      }

      function getTemperatureData5() {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
          if (this.readyState == 4 && this.status == 200) {
            document.getElementById("ValorTemperatura5").innerHTML =
            this.responseText;
          }
        };
        xhttp.open("GET", "temperaturec3", true);
        xhttp.send();
      }

      function getTemperatureData6() {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
          if (this.readyState == 4 && this.status == 200) {
            document.getElementById("ValorTemperatura6").innerHTML =
            this.responseText;
          }
        };
        xhttp.open("GET", "temperaturec4", true);
        xhttp.send();
      }

      </script>
  </body>
</html>
)=====";
