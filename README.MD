
### `broker/`

- **config/**: Contains the Mosquitto configuration file.
- **data/**: Directory for Mosquitto data.
- **docker-compose.yaml**: Docker Compose file to set up the Mosquitto and Node-RED services.
- **log/**: Directory for Mosquitto logs.
- **node-flows/**: Contains Node-RED flow configurations.
- **node-red/**: Contains Node-RED configuration files and settings.
- **old-docker-compos.yaml**: Previous version of the Docker Compose file.

### `thing/`

- **config.h**: Configuration header file.
- **example-config.h**: Example configuration header file.
- **poc_mqtt.ino**: Arduino sketch for MQTT PoC.

## Getting Started

### Prerequisites

- Docker
- Docker Compose

### Setup

1. Clone the repository:
    ```sh
    git clone <repository-url>
    cd mqtt_poc
    ```

2. Navigate to the `broker` directory:
    ```sh
    cd broker
    ```

3. Start the services using Docker Compose:
    ```sh
    docker-compose up -d
    ```

### Configuration

- **Mosquitto**: Configure Mosquitto using the `mosquitto.conf` file located in the `config` directory.
- **Node-RED**: Configure Node-RED using the settings in the `node-red/settings.js` file.

### Usage

- Access the Mosquitto broker on port `1883` for MQTT and port `9001` for WebSockets.
- Access the Node-RED editor at `http://localhost:1880`.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- [Eclipse Mosquitto](https://mosquitto.org/)
- [Node-RED](https://nodered.org/)