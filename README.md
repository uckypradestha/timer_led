<h2>Timer Menggunakan LED</h2>

<p>Interrupt hardware dipicu oleh kejadian eksternal seperti penekanan tombol. Sedangkan interrupt timer dipicu oleh clock internal Arduino. Sebelum kita benar-benar memahami bagaimana interrupt timer bekerja, kita perlu sedikit pengetahuan dasar tentang timer pada Arduino.</p>

<p>Interrupt hardware dipicu oleh kejadian eksternal seperti penekanan tombol. Sedangkan interrupt timer dipicu oleh clock internal Arduino. Sebelum kita benar-benar memahami bagaimana interrupt timer bekerja, kita perlu sedikit pengetahuan dasar tentang timer pada Arduino.</p>

<p>Arduino memiliki tiga timer – Timer0, Timer1, dan Timer2:</p>
<ul>
 <li>Timer0 – timer 8-bit yang digunakan untuk fungsi delay(), millis(), dan micros()</li>
 <li>Timer1 – timer 16-bit</li>
 <li>Timer2 – timer 8-bit</li>
</ul>

<p>Jangan menggunakan Timer0 untuk interrupt karena dapat merusak fungsi delay(), millis(), dan micros(). Sebagai gantinya, gunakan Timer1 atau Timer2.</p>

<p>Ketiga timer pada Arduino bekerja berdasarkan frekuensi clock Arduino, yaitu 16 MHz. Setiap siklus clock dihitung sebagai satu tick pada timer.</p>

<p>Timer1 adalah timer 16-bit, yang berarti dapat menghitung hingga maksimum 2¹⁶ = 65.535 sebelum penuh. Ketika mencapai nilai tersebut, timer akan kembali ke nol dan mulai menghitung lagi.</p>

<p>Timer0 dan Timer2 adalah timer 8-bit, sehingga hanya dapat menghitung hingga maksimum 2⁸ = 256 sebelum penuh.</p>

<p>Kecepatan timer dapat diperlambat menggunakan nilai prescaler. Dengan mengubah nilai prescaler, kita dapat mengatur lama waktu perhitungan timer.</p>

<p>Berikut adalah contoh penerapan Timer1 menggunakan LED</p>

<h2>Konfigurasi Pin<h2>
<ul>
 <li>LED 1 ----- Pin 5</li>
 <li>LED 2 ----- Pin 11</li>
</ul>