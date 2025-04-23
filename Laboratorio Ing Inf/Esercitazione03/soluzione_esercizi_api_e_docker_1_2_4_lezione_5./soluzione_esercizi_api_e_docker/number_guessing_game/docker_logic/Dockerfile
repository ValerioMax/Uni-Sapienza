# Use a lightweight Python image
FROM python:3.9-slim

# Set working directory
WORKDIR /app

# Copy the source code into the container
COPY src /app

# Install required dependencies for the logic server
RUN pip install --no-cache-dir fastapi uvicorn

# Expose the port for FastAPI
EXPOSE 8000

# Start the logic server (make sure your file is named "logic_server.py" and defines "app")
CMD ["uvicorn", "logic_server:app", "--host", "0.0.0.0", "--port", "8000"]
