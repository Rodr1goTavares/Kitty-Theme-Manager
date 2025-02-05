
#!/bin/sh

LOCAL_BIN="$HOME/.local/bin/ktm"
GLOBAL_BIN="/usr/local/bin/ktm"

if [ -f "$LOCAL_BIN" ]; then
    echo "Removing ktm from $LOCAL_BIN..."
    rm -f "$LOCAL_BIN"
fi

if [ -f "$GLOBAL_BIN" ]; then
    echo "Removing ktm de $GLOBAL_BIN..."
    sudo rm -f "$GLOBAL_BIN"
fi

CONFIG_FILE="$HOME/.bashrc"
if grep -q "$HOME/.local/bin" "$CONFIG_FILE"; then
    echo "Removing $HOME/.local/bin from $CONFIG_FILE"
    sed -i '/\.local\/bin/d' "$CONFIG_FILE"
fi

CONFIG_FILE="$HOME/.zshrc"
if grep -q "$HOME/.local/bin" "$CONFIG_FILE"; then
    echo "Removing $HOME/.local/bin from $CONFIG_FILE"
    sed -i '/\.local\/bin/d' "$CONFIG_FILE"
fi

if [ -f "$HOME/.config/fish/config.fish" ]; then
    echo "Removing $HOME/.local/bin from config.fish"
    sed -i '/\.local\/bin/d' "$HOME/.config/fish/config.fish"
fi

CONFIG_DIR="$HOME/.config/ktm"
if [ -d "$CONFIG_DIR" ]; then
    echo "Removing configs in $CONFIG_DIR..."
    rm -rf "$CONFIG_DIR"
fi

echo "ktm removed ! Restart terminal to apply changes."

