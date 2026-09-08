.global _start
.intel_syntax noprefix

_start:
    
    mov rax, 1 #write
    mov rdi, 1 #write intruction
    lea rsi, [hello_world] 
    mov rdx, 14 #string limit
    syscall #system call

    mov rax, 60 #exit safely
    mov rdi, 69 #executes but doesnt print 
    syscall

hello_world:
    .asciz "Hello World\n"


from flask import Flask, render_template
from gpiozero import LED

app = Flask(__name__)

# Initialize dictionary of LEDs mapped to their respective GPIO pins
leds = {
    17: LED(17),
    26: LED(26),
    16: LED(16)
}

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/led/<int:pin>/<state>')
def led_control(pin, state):
    # Check if requested pin exists in our configuration
    if pin in leds:
        if state == 'on':
            leds[pin].on()
            message = f"GPIO {pin} turned ON"
        elif state == 'off':
            leds[pin].off()
            message = f"GPIO {pin} turned OFF"
        else:
            message = "Invalid state requested"
    else:
        message = f"GPIO {pin} is not configured"
        
    return render_template('index.html', message=message)

if __name__ == '__main__':
    # Run server accessible on local network
    app.run(host='0.0.0.0', port=5000)





<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>LED Control Panel</title>
</head>
<body>
    <h1>Home Lighting Control</h1>
    
    <!-- Status Message Display -->
    {% if message %}
        <p><strong>Status:</strong> {{ message }}</p>
    {% else %}
        <p><strong>Status:</strong> System Ready</p>
    {% endif %}

    <hr>

    <!-- Bedroom Light (GPIO 17) -->
    <section>
        <h2>Yourname's Bedroom Light (GPIO 17)</h2>
        <form action="/led/17/on" method="get" style="display: inline;">
            <button type="submit">Turn ON</button>
        </form>
        <form action="/led/17/off" method="get" style="display: inline;">
            <button type="submit">Turn OFF</button>
        </form>
    </section>

    <!-- Living Room Light (GPIO 26) -->
    <section>
        <h2>Yourname's Living Room Light (GPIO 26)</h2>
        <form action="/led/26/on" method="get" style="display: inline;">
            <button type="submit">Turn ON</button>
        </form>
        <form action="/led/26/off" method="get" style="display: inline;">
            <button type="submit">Turn OFF</button>
        </form>
    </section>

    <!-- Kitchen Light (GPIO 16) -->
    <section>
        <h2>Yourname's Kitchen Light (GPIO 16)</h2>
        <form action="/led/16/on" method="get" style="display: inline;">
            <button type="submit">Turn ON</button>
        </form>
        <form action="/led/16/off" method="get" style="display: inline;">
            <button type="submit">Turn OFF</button>
        </form>
    </section>
</body>
</html>
