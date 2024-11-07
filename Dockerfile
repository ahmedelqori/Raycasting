# Use a base image with Ubuntu (or a similar lightweight Linux distribution)
FROM ubuntu:latest

RUN apt-get update && \
    apt-get install -y \
    build-essential \
    libx11-dev \
    libxext-dev \
    libbsd-dev \
    git \
    make \
    gcc \
    xorg-dev \
    libpng-dev \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY . .

RUN make

ENV DISPLAY=:0

CMD ["./cub3D", "./maps/mandatory/a.cub"]
