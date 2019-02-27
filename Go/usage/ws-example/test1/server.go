package main

import (
	"encoding/json"
	"flag"
	"github.com/gorilla/websocket"
	"html/template"
	"log"
	"net/http"
)

var upgrader = websocket.Upgrader{} // use default options

func echo(w http.ResponseWriter, r *http.Request) {
	c, err := upgrader.Upgrade(w, r, nil)
	if err != nil {
		log.Print("upgrade:", err)
		return
	}
	defer c.Close()
	for {
		mt, message, err := c.ReadMessage()
		if err != nil {
			log.Println("read:", err)
			break
		}
		var objmap map[string]interface{}
		_ = json.Unmarshal(message, &objmap)
		event := objmap["event"].(string)
		sendData := map[string]interface{}{
			"event": "res",
			"data":  nil,
		}
		switch string(event) {
		case "open":
			log.Printf("Received: %s\n", event)
		case "req":
			sendData["data"] = objmap["data"]
			log.Printf("Received: %s\n", event)
		}
		refineSendData, err := json.Marshal(sendData)
		err = c.WriteMessage(mt, refineSendData)
		if err != nil {
			log.Println("write:", err)
			break
		}
	}
}

func home(w http.ResponseWriter, r *http.Request) {
	homeTemplate.Execute(w, "ws://"+r.Host+"/echo")
}

func main() {
	http.HandleFunc("/echo", echo)
	http.HandleFunc("/", home)
	log.Fatal(http.ListenAndServe("localhost:8080", nil))
}

var homeTemplate = template.Must(template.New("").Parse(`
<html>
<head>
    <title>ws</title>
    <link rel='stylesheet' href='/stylesheets/style.css'/>
    <script src="https://code.jquery.com/jquery-3.3.1.min.js"></script>
</head>
<body>
<textarea rows="20" cols="30" id="chat"></textarea><br>
<input type="text" id="user"><input type="button" value="msg submit" onclick="myOnClick()">
</body>
<script>
    var ws = new WebSocket('{{.}}');
    ws.onopen = (event) => {
        let sendData = {event: 'open'}
        ws.send(JSON.stringify(sendData));
    }
    ws.onmessage = (event) => {
        console.log(event.data);
        let recData = JSON.parse(event.data);
        switch (recData.event) {
            case 'res':
                $('#chat').val($('#chat').val() + recData.data.comment + '\n');
                break;
            default:
        }
    }

    function myOnClick() {
        let sendData = {event: 'req', data: {comment: $('#user').val()}};
        ws.send(JSON.stringify(sendData));
        $('#user').val('');
    }
</script>
</html>
`))
