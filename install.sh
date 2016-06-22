main() {
  # Use colors, but only if connected to a terminal, and that terminal
  # supports them.
  if which tput >/dev/null 2>&1; then
      ncolors=$(tput colors)
  fi
  if [ -t 1 ] && [ -n "$ncolors" ] && [ "$ncolors" -ge 8 ]; then
    RED="$(tput setaf 1)"
    GREEN="$(tput setaf 2)"
    YELLOW="$(tput setaf 3)"
    BLUE="$(tput setaf 4)"
    BOLD="$(tput bold)"
    NORMAL="$(tput sgr0)"
  else
    RED=""
    GREEN=""
    YELLOW=""
    BLUE=""
    BOLD=""
    NORMAL=""
  fi

  printf "${BLUE}Cloning ccock/cut...${NORMAL}\n"

  hash git >/dev/null 2>&1 || {
    echo "Error: git is not installed"
    exit 1
  }

  env git clone https://github.com/ccock/cut.git || {
    printf "Error: git clone of ccock/cut repo failed\n"
    exit 1
  }
  cd cut

  printf "${BLUE}Looking for an existing ccock/cut...${NORMAL}\n"
  if [ -f /usr/local/lib/libcut.a ]; then
    printf "${YELLOW}Found ccock/cut installed.${NORMAL} ${GREEN}Clearing prev version.${NORMAL}\n";
    sudo rm -rf /usr/local/include/cub
    sudo rm -rf /usr/local/include/cut
    sudo rm -rf /usr/local/include/cum
    sudo rm -rf /usr/local/include/cpo
    sudo rm -rf /usr/local/lib/libcub.a
    sudo rm -rf /usr/local/lib/libcut.a
    sudo rm -rf /usr/local/lib/libcum.a
    sudo rm -rf /usr/local/lib/libcpo.a
  fi

  printf "${BLUE}Installing ccock/cut...${NORMAL}\n"
  env ./gradlew || {
    printf "Error: install ccock/cut failed.\n"
    exit 1
  }

  printf "${GREEN}"
  echo ' ccock/cut is now installed!'
  echo ''
  echo 'p.s. Follow us at https://github.com/ccock/cut/README.md'
  echo ''
  printf "${NORMAL}"
}

main
