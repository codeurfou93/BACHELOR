FROM ubuntu:22.04

# install app dependencies
RUN apt-get update && apt-get install -y python3 python3-pip
RUN pip install flask==3.0.*

WORKDIR /app

# install app
COPY site_flask_1_2.py site_flask.py
COPY static static
COPY templates templates

# final configuration
ENV FLASK_APP=site_flask
EXPOSE 8000
CMD ["flask", "run", "--host", "0.0.0.0", "--port", "8000"]