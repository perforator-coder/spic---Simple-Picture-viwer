
pkgname=spic
pkgver=r30.614687c
pkgrel=1
pkgdesc="Просмоторщик фото"
arch=('x86_64')
url="https://github.com/perforator-coder/spic---Simple-Picture-viwer"
license=('GPL')

# Зависимости, необходимые для работы приложения в Arch
# Укажите qt6-base (для Qt6) или qt5-base (для Qt5)
depends=('qt6-base' 'hicolor-icon-theme' ) 

# Зависимости, нужные только для сборки
makedepends=('cmake' 'ninja' 'git') 

# Укажите, откуда скачивается исходный код (или локальный архив)
source=("git+${url}")
sha256sums=('SKIP') # Замените на реальный хеш или оставьте SKIP для тестов
pkgver() {

  cd "spic---Simple-Picture-viwer"
  printf "r%s.%s" "$(git rev-list --count HEAD)" "$(git rev-parse --short HEAD)"



}

build() {

  cd "spic---Simple-Picture-viwer"
  cmake -B build -S . -DCMAKE_BUILD_TYPE=Release
  cmake --build build
}

package() {
  cd "spic---Simple-Picture-viwer"
  install -Dm755 "build/spic" "$pkgdir/usr/bin/Spic"
   install -Dm644 "icons/icon.png" "$pkgdir/usr/share/icons/hicolor/512x512/apps/Spic.png"
   install -Dm644 "Spic.desktop" "$pkgdir/usr/share/applications/Spic.desktop"
}
