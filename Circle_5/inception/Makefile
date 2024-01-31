.PHONY: all up down clean setup-dirs delete-dirs

all: setup-dirs up

setup-dirs:
	@mkdir -p /home/jikoo/data/db-data
	@mkdir -p /home/jikoo/data/wp-files

up:
	@echo "Starting containers ..."
	@docker compose -f srcs/docker-compose.yml up -d

down:
	@echo "Stopping containers ..."
	@docker compose -f srcs/docker-compose.yml down

clean: down
	@echo "Cleaning unused Docker resources ..."
	@docker system prune -af

delete-dirs:
	@sudo rm -rf /home/jikoo/data