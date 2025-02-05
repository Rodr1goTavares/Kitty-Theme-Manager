
#!/bin/sh

OS=$(uname -s)
ARCH=$(uname -m)

case "$OS" in
    Linux)   FILE="ktm-linux-amd64" ;;
    Darwin)  FILE="ktm-macos-arm64" ;;
    *) echo "System not supported!" && exit 1 ;;
esac

GITHUB_REPO="Rodr1goTavares/Kitty-Theme-Manager"
VERSION="latest"  # Or specify version. ex: "v1.0.0"
URL="https://github.com/$GITHUB_REPO/releases/$VERSION/download/$FILE"

BIN_DIR="$HOME/.local/bin"
BIN_PATH="$BIN_DIR/ktm"

mkdir -p "$BIN_DIR"

echo "Baixando $FILE de $URL..."
wget -q --show-progress -O "$BIN_PATH" "$URL"

chmod +x "$BIN_PATH"

# Garantir que o diretório está no PATH
if ! echo "$PATH" | grep -q "$BIN_DIR"; then
    echo "Adicionando $BIN_DIR ao PATH..."
    case "$SHELL" in
        */bash) echo 'export PATH="$HOME/.local/bin:$PATH"' >> "$HOME/.bashrc" ;;
        */zsh)  echo 'export PATH="$HOME/.local/bin:$PATH"' >> "$HOME/.zshrc" ;;
        */fish) echo 'set -Ux PATH $HOME/.local/bin $PATH' >> "$HOME/.config/fish/config.fish" ;;
        *)      echo 'export PATH="$HOME/.local/bin:$PATH"' >> "$HOME/.profile" ;;
    esac
fi

echo "Instation finished! Restart your shell to use."
