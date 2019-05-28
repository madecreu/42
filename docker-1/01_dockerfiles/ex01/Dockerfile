FROM debian:latest


RUN apt-get update -y 
RUN apt-get upgrade -y 
RUN apt-get install wget -y
RUN wget http://dl.4players.de/ts/releases/3.0.11.2/teamspeak3-server_linux-amd64-3.0.11.2.tar.gz
RUN tar -zxvf teamspeak3-server_linux-amd64-3.0.11.2.tar.gz
RUN chmod -R 777 /teamspeak3-server_linux-amd64

CMD ["/teamspeak3-server_linux-amd64/ts3server_minimal_runscript.sh"]

#docker run -it -p 9987:9987/udp -p 10011:10011 -p 30033:30033 plop:plop
