import requests

URL = "http://localhost:8007"

response = requests.get(URL)
response.raise_for_status()
print(response.text)