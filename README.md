# fide
Free Integrated Development Environment

# A project of a person with ADHD.

Fide: A simple, lightweight, and cross-platform IDE written in a C language. Developed with GTK, Fide aims to make the software development process more efficient with a user-friendly interface. It currently has basic text editor features, with plans to add more features and customization options in the future. Fide aims to offer a fast and effective environment for both beginners and experienced developers. Soon the source codes of the project will be with you.


Türkish

Fide: Basit, hafif ve çapraz platform bir C dilinde yazılmış IDE. GTK ile geliştirilmiş olan Fide, kullanıcı dostu bir arayüzle, yazılım geliştirme sürecini daha verimli hale getirmeyi hedefler. Şu anda temel metin düzenleyicisi özelliklerine sahip olup, ilerleyen zamanlarda daha fazla özellik ve özelleştirme seçenekleri eklenmesi planlanmaktadır. Fide, hem yeni başlayanlar hem de deneyimli geliştiriciler için hızlı ve etkili bir ortam sunmayı amaçlar. Yakında projenin kaynak kodları sizinle.


Developing with GTK4

```
sudo apt update
sudo apt install libgtk-4-dev
sudo apt install libgdk-4-dev
sudo apt install gobject-introspection
sudo apt install pkg-config
sudo apt-get install libgtksourceview-5-dev

```

for build:  ```  gcc $(pkg-config --cflags gtk4 gtksourceview-5) -o fide main.c $(pkg-config --libs gtk4 gtksourceview-5) ```
