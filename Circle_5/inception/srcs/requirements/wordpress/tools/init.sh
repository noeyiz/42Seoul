#!/bin/sh

if [ ! -f "/var/www/html/index.php" ]; then
    wp core download

    wp config create \
    --dbhost=mariadb \
    --dbname=$MYSQL_DATABASE \
    --dbuser=$MYSQL_USER \
    --dbpass=$MYSQL_PASSWORD

    wp core install \
    --url=$WORDPRESS_URL \
    --title=$WORDPRESS_TITLE \
    --admin_user=$WORDPRESS_ADMIN \
    --admin_password=$WORDPRESS_ADMIN_PASSWORD \
    --admin_email=$WORDPRESS_ADMIN_MAIL \
    --skip-email

    wp user create $WORDPRESS_USER $WORDPRESS_USER_MAIL --user_pass=$WORDPRESS_USER_PASSWORD
fi

exec php-fpm81 -F