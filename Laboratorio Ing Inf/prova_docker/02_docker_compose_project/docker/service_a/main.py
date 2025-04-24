from fastapi import FastAPI

app = FastAPI()

@app.get("/")
def read_root():
    data = {"message": "Hello World from service_a!!!"}
    return data