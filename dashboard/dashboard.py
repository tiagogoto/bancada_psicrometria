from asyncio import timeout
import json
from tempfile import template
import requests
from datetime import datetime
import pandas as pd
import plotly.express as px
import plotly.graph_objects as go
from dash import Dash, dcc, html
from dash.dependencies import Input, Output


url = "192.168.4.1/api"
df = pd.DataFrame(
    {
        "umidade1": [],
        "umidade2": [],
        "tempdht": [],
        "tempdht2": [],
        "Temperatura1": [],
        "Temperatura2": [],
        "Temperatura3": [],
        "Temperatura4": [],
        "horario": [],
    }
)


def get_data(df):
    url = "http://192.168.4.1/api"
    r = requests.get(url)
    data = r.json()
    # print(data)
    agora = datetime.now()
    horario_formatado = agora.strftime("%H:%M:%S")
    data["horario"] = horario_formatado
    df.loc[len(df)] = data
    # print(df.header())
    return df


app = Dash(__name__)
app.title = "Dashboard em Tempo Real"
app.layout = html.Div(
    [
        html.H2(
            "Valores da umidade entrada e saída (atualização automática):",
            style={"textAlign": "Center"},
        ),
        dcc.Graph(id="grafico-umidade"),
        html.H2(
            "Valores da Temperatura  do sensor DHT 22 entrada e saída (atualização automática):",
            style={"textAlign": "Center"},
        ),
        dcc.Graph(id="grafico-temp-dht"),
        html.H2(
            "Valores da Temperatura dos sensores DS18B20 (atualização automática):",
            style={"textAlign": "Center"},
        ),
        dcc.Graph(id="grafico-temp"),
        html.Div(
            id="ultima-atualizacao", style={"textAlign": "Center", "marginTop": "10px"}
        ),
        dcc.Interval(id="intervalo-atualizacao", interval=5 * 1000, n_intervals=0),
    ]
)


@app.callback(
    Output("grafico-umidade", "figure"),
    Output("ultima-atualizacao", "children"),
    Input("intervalo-atualizacao", "n_intervals"),
)
def atualizar_grafico(n):
    global df
    df = get_data(df)
    print(df.tail())
    fig_go = go.Figure()
    fig_go.add_trace(
        go.Scatter(x=df["horario"], y=df["umidade1"], mode="lines", name="Umidade 1")
    )
    fig_go.add_trace(
        go.Scatter(x=df["horario"], y=df["umidade2"], mode="lines", name="Umidade 2")
    )
    fig_go.update_layout(yaxis_title="Umidade [%]", template="plotly_white")

    fig_go_dht22 = go.Figure()
    fig_go_dht22.add_trace(
        go.Scatter(
            x=df["horario"], y=df["tempdht"], mode="lines", name="Temperatura Sensor 1 "
        )
    )
    fig_go_dht22.add_trace(
        go.Scatter(
            x=df["horario"],
            y=df["tempdht2"],
            mode="lines",
            name="Temperatura Sensor 2 ",
        )
    )
    fig_go_dht22.update_layout(yaxis_title="Temperatura [°C]", template="plotly_white")
    fig_go_temps = go.Figure()
    fig_go_temps.add_trace(
        go.Scatter(
            x=df["horario"], y=df["Temperatura1"], mode="lines", name="Temperatura 1"
        )
    )
    fig_go_temps.add_trace(
        go.Scatter(
            x=df["horario"], y=df["Temperatura2"], mode="lines", name="Temperatura 2"
        )
    )
    fig_go_temps.add_trace(
        go.Scatter(
            x=df["horario"], y=df["Temperatura3"], mode="lines", name="Temperatura 3"
        )
    )
    fig_go_temps.add_trace(
        go.Scatter(
            x=df["horario"], y=df["Temperatura4"], mode="lines", name="Temperatura 4"
        )
    )
    fig_go_temps.update_layout(yaxis_title="Temperatura [°C]", template="plotly_white")
    return fig_go, f"útilma atualização:{df['horario'].tolist()[-1]}"


if __name__ == "__main__":
    app.run(debug=True)
