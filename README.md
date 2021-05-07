# mqtt_Led_Control
arduino control Led using mqtt &amp; node-red

<h2>1.Preparing</h2>

1-1. mosquitto install
<https://mosquitto.org/>

* find mosquitto.conf and edit

allow_anonymous true

listener 1883

1-2. node-red install

install node.js
<https://nodejs.org/>

* check installed npm in cmd

<pre><code>npm -v</code></pre>

* install node-red
<pre><code>npm install *g --unsafe-perm node-red</code></pre>

<h2>2. server Setting</h2>
control panel-> fire wall -> advanced settings

inbound rules -> new rule -> port-> tcp & S 1883 -> A -> set name

* mosquitto execute
cd mosquitto install path
<pre><code>mosquitto -c mosquitto.conf -v</code></pre>

* in cmd check mosquitto port

<pre><code>netstat -an</code></pre>

* find port 0:0:0:0:1883

end


