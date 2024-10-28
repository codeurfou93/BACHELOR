# syntax=docker/dockerfile:1
FROM ubuntu:22.04

# install app dependencies
RUN apt-get update && apt-get install -y python3 python3-pip
RUN pip install Flask==2.3.*

# install app
COPY multiplier_1_0.py multiplier.py

# expose the desired port
EXPOSE 8000

# final configuration to run the app
CMD ["python3", "multiplier.py"]
