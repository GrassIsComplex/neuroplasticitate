import http.server
import socketserver
import os

os.chdir("jocweb")
port = 6767
handler = http.server.SimpleHTTPRequestHandler
with socketserver.TCPServer(("", port), handler) as httpd:
    print("http://127.0.0.1:",port,"/",sep='')
    httpd.serve_forever()

