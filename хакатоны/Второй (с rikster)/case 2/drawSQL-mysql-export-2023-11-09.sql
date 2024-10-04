CREATE TABLE `events`(
    `id` BIGINT UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY,
    `name` VARCHAR(255) NOT NULL,
    `date` DATETIME NOT NULL,
    `country` VARCHAR(255) NOT NULL,
    `stadium` VARCHAR(255) NOT NULL,
    `tag_name` VARCHAR(255) NOT NULL,
    `image` VARCHAR(255) NOT NULL
);
CREATE TABLE `users`(
    `id` BIGINT UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY,
    `username` VARCHAR(255) NOT NULL,
    `name` VARCHAR(255) NOT NULL,
    `password` VARCHAR(255) NOT NULL,
    `tags` JSON NOT NULL
);
ALTER TABLE
    `users` ADD UNIQUE `users_username_unique`(`username`);