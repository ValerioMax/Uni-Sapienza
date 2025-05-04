FROM python:3.9-slim

WORKDIR /app

RUN apt-get update && \
    apt-get install -y libmariadb-dev build-essential curl

COPY requirements.txt .
RUN pip install --no-cache-dir -r requirements.txt

COPY . .

EXPOSE 8003

CMD ["uvicorn", "src.backend.backend:app", "--host", "0.0.0.0", "--port", "8003"]