#!/usr/bin/env bash

DATA_TO_BACKUP="rep_src"

BACKUP_DIR="rep_dest"

DATE=$(date +"%y%m%d-%H%M%S")

ARCHIVE_NAME="svg._${DATE}.tar.bz2"
ARCHIVE_PATH="${BACKUP_DIR}/${ARCHIVE_NAME}"

mkdir -p "$BACKUP_DIR"

echo "Sauvegarde de $DATA_TO_BACKUP dans $ARCHIVE_PATH"
tar cvjf "$ARCHIVE_PATH" --newer-mtime='1 day ago' "$DATA_TO_BACKUP"

echo "Sauvegarde terminee."

