FROM python:3.9-slim

WORKDIR /app

COPY src /app
COPY templates /app/templates

RUN pip install --no-cache-dir fastapi uvicorn jinja2 requests python-multipart

ENV API_URL=http://logic:8000

EXPOSE 8001

CMD ["uvicorn", "html_server:app", "--host", "0.0.0.0", "--port", "8001"]
