void led()
{
    while(1){
    if (digitalRead(D1)==1){
    digitalWrite(D2,LOW);
    }
  else{
    digitalWrite(D2,HIGH);
    server.send(200, "text/html", "<p><a href=/htdocs/jewel.php><button>Toggle LED</button></a></p><body bgcolor=\"#ffa500\">");
    }
  if (digitalRead(D5)==1){
    digitalWrite(D4,LOW);
    }
  else{
    digitalWrite(D4,HIGH);
    server.send(200, "text/html", "<p><a href=/htdocs/jewel.php><button>Toggle LED</button></a></p><body bgcolor=\"#ffa500\">");
    }
  if (digitalRead(D6)==1){
    digitalWrite(D7,LOW);
    }
  else{
    digitalWrite(D7,HIGH);
    server.send(200, "text/html", "<p><a href=/htdocs/jewel.php><button>Toggle LED</button></a></p><body bgcolor=\"#ffa500\">");
    }
}