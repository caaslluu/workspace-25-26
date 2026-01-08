#!/usr/bin/env bash

BACKUP_DIR="rep_dest"

if [ ! -d "$BACKUP_DIR" ]; then
    echo "Le dossier de sauvegarde '$BACKUP_DIR' n'existe pas."
    exit 1
fi

archives=($(ls "$BACKUP_DIR"/svg._*.tar.bz2 2>/dev/null))

if [ ${#archives[@]} -eq 0 ]; then
    echo "Aucune archive de sauvegarde trouvée dans $BACKUP_DIR"
    exit 1
fi

echo "Archives disponibles :"
for i in "${!archives[@]}"; do
    echo "$i - $(basename "${archives[$i]}")"
done

read -p "Choisir l'archive à restaurer : " choix

if ! [[ "$choix" =~ ^[0-9]+$ ]] || [ "$choix" -ge "${#archives[@]}" ]; then
    echo "Choix invalide."
    exit 1
fi

archive="${archives[$choix]}"
echo "Restauration de $(basename "$archive")..."
tar xvjf "$archive"

echo "Restauration terminée."
