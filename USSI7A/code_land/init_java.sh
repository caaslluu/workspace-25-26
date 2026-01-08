#!/bin/bash

# === PARAMÈTRES ===
PROJECT_NAME=${1:-mon-projet}
CLASS_NAME=${2:-Main}

# === CHEMINS ===
SRC_DIR="$PROJECT_NAME/src"
BIN_DIR="$PROJECT_NAME/bin"
MAIN_FILE="$SRC_DIR/${CLASS_NAME}.java"

# === CRÉATION DE L'ARBORESCENCE ===
echo "📁 Création du projet '$PROJECT_NAME'..."
mkdir -p "$SRC_DIR" "$BIN_DIR"

# === FICHIER Main.java ===
if [ -f "$MAIN_FILE" ]; then
    echo "⚠️  $MAIN_FILE existe déjà. Non modifié."
else
    echo "📝 Création de $MAIN_FILE avec Hello World..."
    cat > "$MAIN_FILE" <<EOF
public class $CLASS_NAME {
    public static void main(String[] args) {
        System.out.println("Hello, world!");
    }
}
EOF
fi

# === FIN ===
echo "✅ Projet Java minimal créé dans '$PROJECT_NAME'."
echo "➡️  Source : $MAIN_FILE"
echo "➡️  Bin (vide) : $BIN_DIR"
echo "📌 Pour compiler :"
echo "   cd $PROJECT_NAME && javac -d bin src/$CLASS_NAME.java"
echo "📌 Pour exécuter :"
echo "   java -cp bin $CLASS_NAME"

