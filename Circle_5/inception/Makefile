.PHONY: all up down clean vclean setup-dirs

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

vclean:
	@sudo rm -rf /home/jikoo/data
	@docker volume rm srcs_db-volume
	@docker volume rm srcs_wp-volume