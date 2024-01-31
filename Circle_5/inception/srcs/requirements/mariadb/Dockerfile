FROM alpine:3.18

# MariaDB 설치
RUN apk add --no-cache mariadb mariadb-client && \
mkdir -p /run/mysqld /var/lib/mysql && \
chown -R mysql:mysql /run/mysqld /var/lib/mysql

# 포트 노출
EXPOSE 3306

# MariaDB 초기화 및 실행 스크립트 복사 후 실행
COPY tools/init.sh /tmp/init.sh
ENTRYPOINT [ "sh", "/tmp/init.sh" ]