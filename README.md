# SENTSOR Name Card Information Injector
## Introduction
<img src="https://github.com/adamalfath/sentsor-ncii/blob/master/media/ncii-img0.jpg" width="600">  

NCII ini bukanlah panggilan buat guru ya (encik guru a.k.a. cikgu) dan juga bukan berasal dari cici yang senantiasa menemani koko :D. NCII merupakan singkatan dari **N**ame **C**ard **I**nformation **I**njector yaitu sebuah kartu nama (**NC**) dengan dimensi standar ID-1 (ISO/IEC 7810) yang dibekali sirkuit mikrokontroler fungsional. MCU yang digunakan adalah ATmega32U4 yang kompatible dengan bootloader Arduino (ex: Micro, Leonardo) sehingga dapat memudahkan pengguna untuk bereksporasi, memainkan basic input/output berupa push button & LED, bahkan untuk pemula sekalipun.

Fitur yang tak kalah pentingnya dari MCU ini yaitu native USB, yang mana bisa menjadikan board ini berfungsi sebagai USB HID seperti mensimulasikan fungsi keyboard atau mouse. Hal inilah yang membuat board ini memiliki fitur injeksi informasi (**II**), dengan memprogram board ini sebagai USB HID, kita bisa secara otomatis mengetikan informasi pada host. Sebagai contoh: injeksi tulisan; malas ngetik email? atau punya email kerja/email personal/email bisnis dan alamat email berjibun lainnya? klik NCII; malas nulis nama lengkap? klik NCII; alamat rumah yang panjang? klik NCII; ngantor, nyalain PC dan langsung buka program favorit, jreng, office+spotify+chrome+vscode langsung muncul, alternatif tanpa harus ngubah startup di PC. Atau disaat jobfair dan orang lain masih bawa CV kertas, kamu sodorkan NCII ini sebagai kartu nama kamu, interview dengan PD sambil ditemani NCII, porfolio real kamu lalu kasih tau cara pakainya, boom, *and that's how you impress them*.  

Dan masih sangat banyak yang bisa kamu lakukan dengan board ini. Kenapa alasannya kamu harus coba NCII ini? karena why not? Board ini simple yet functional serta open source. Link untuk file design EDA disediakan dibawah, kalian bebas melakukan modifikasi sesuai kebutuhan. Semoga bermanfaat dan selamat berkarya!

## How to Use
Cukup hubungkan PCB NCII ke PC menggunakan kabel MicroUSB (atau HP via OTG). Buka IDE kesukaanmu dan pilih board Arduino Micro (default). Pinout bisa dilihat secara lengkap di file skematik. Untuk fitur USB HID, kalian bisa mempelajarinya secara lengkap di dokumentasi [keyboard](https://www.arduino.cc/reference/en/language/functions/usb/keyboard/) dan [mouse](https://www.arduino.cc/reference/en/language/functions/usb/mouse/) pada link tersebut. Beberapa contoh juga disediakan di folder example sebagai referensi, tapi yang terpenting imajinasi dan kode dari kalian sendirilah yang bisa membuat board ini jadi lebih bermakna.

**DEMO:** https://www.youtube.com/watch?v=JQNkF4G7ug0

**PERHATIAN!**
Dengan mengaktifkan fungsi HID, board NCII akan bertindak layaknya input keyboard dan mouse yang asli. Pastikan kalian jeli mengontrol syntax terkait.

## Bill of Materials
|Designator|Qty|Name/Value	|Footprint|
|-|-|-|-|
|U1|1|ATMEGA32U4-AU|QFP-44|
|R1|1|10k|R0603|
|R3,R2|2|22|R0603|
|R10,R6,R13,R12,R11,R9,R8,R7,R5,R4|10|1k|R0603|
|R14|1|330|R0603|
|C2,C1|2|22p|C0603
|C3|1|100n|C0603|
|C5,C4|2|1u|C0603|
|X1|1|16MHz|OSC-SMD_4P-L5.0-W3.2-BL|
|LED1|1|White|LED0603|
|SW1|1|HAD-04H-R|DIPSW-SMD_8P-P=2.54mm|
|SW4,SW5,SW6,SW7,SW2,SW3|6|Tact Switch|3X6X2.5_SMD|
|CN1|1|MicroUSB|MICRO-USB-16|

## Design 
<img src="https://github.com/adamalfath/sentsor-ncii/blob/master/media/ncii-pcb-ss.png" width="600">  

NCII merupakan open source hardware, silahkan dimanfaatkan secara bijaksana.  

Link: https://easyeda.com/sentsor-project/sentsor-namecard

## Gallery
<img src="https://github.com/adamalfath/sentsor-ncii/blob/master/media/ncii-img1.jpg" width="400"> <img src="https://github.com/adamalfath/sentsor-ncii/blob/master/media/ncii-img2.jpg" width="400">  
<img src="https://github.com/adamalfath/sentsor-ncii/blob/master/media/ncii-img3.jpg" width="400"> <img src="https://github.com/adamalfath/sentsor-ncii/blob/master/media/ncii-img4.jpg" width="400">
<img src="https://github.com/adamalfath/sentsor-ncii/blob/master/media/ncii-img5.jpg" width="400"> <img src="https://github.com/adamalfath/sentsor-ncii/blob/master/media/ncii-img6.jpg" width="400">

## Support Open-Source Hardware & SENTSOR!
Bila kalian tertarik dengan produk-produk SENTSOR, kalian bisa cek marketplace di link berikut:  
https://www.tokopedia.com/gerai-sagalarupa/etalase/sentsor-product  
Support kalian akan sangat membantu untuk pengembangan open-source hardware dari SENTSOR selanjutnya.

## Information
SENTSOR  
Author: Adam Alfath  
Contact: adam.alfath23@gmail.com  
Web: [sentsor.net](http://www.sentsor.net)  
Repo: [SENTSOR Main Repo](http://github.com/adamalfath/sentsor)

<a rel="license" href="http://creativecommons.org/licenses/by-sa/4.0/"><img alt="Creative Commons License" style="border-width:0" src="https://i.creativecommons.org/l/by-sa/4.0/88x31.png" /></a><br /><span xmlns:dct="http://purl.org/dc/terms/" property="dct:title">SENTSOR NCII</span> is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by-sa/4.0/">Creative Commons Attribution-ShareAlike 4.0 International License</a>.
