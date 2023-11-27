# veri-yap-lar-1.-dev
Bağlı liste işlemleri
MinGW C++ ortamında derlenen bir program yazılacaktır.
Bu ödevde tek yönlü bağlı listeler kullanarak tam sayılar üzerinde çeşitli işlemler yapılması 
istenmektedir.
Uygulamanız Sayilar.txt dosyası içerisindeki tam sayıları okuyacaktır. Aşağıda bu dosyaya bir örnek 
verilmiştir (Dosya içerisindeki sayı adedi değişebilir). Sayılar arasında tek bir boşluk bulunacaktır.
Her bir sayı bir bağlı listede tutulacaktır. Okunan sayının basamakları listenin düğümleri olacaktır.

• Her bir basamağın tutulacağı düğüm sınıfı Basamak isminde olacaktır.
• Basamakları bir arada tutacak olan liste sınıfının ismi Sayi olacaktır.

Sayi listelerini tutmak için SayilarListesi isimli bir bağlı liste sınıfı tasarlanacaktır. Bu listenin her bir 
düğümünde bir Sayi listesi barındırılacaktır. SayilarListesi listesinin düğümleri içinde Dugum isimli bir 
sınıf tasarlanması gerekmektedir.

. Kullanıcı 1 değerini 
seçtiğinde her bir Sayi listesindeki basamak düğümlerinin tek değer tutanları listenin başına 
taşınmalıdır. Aşağıdaki şekilde bu işleme bir örnek göstermektedir. Tek olan düğümler listenin başına 
taşınmıştır. Eğer dikkat edecek olursanız taşınan düğümünün adresi değişmemiştir. Yani 
düğümlerinin değerlerinin değiştirilmesi kabul edilmeyecektir. Düğümlerin listede konum 
değiştirmesi gerekmektedir.
Kullanıcı 2.seçeneği seçtiğinde Sayıların basamak düğümleri sondan başa gelecek şekilde yer 
değiştirmelidir. Bir önceki seçenekte olduğu gibi düğümlerin verilerini değiştirmek yeterli değildir. 
Düğümlerin listedeki konumu değişmelidir. Düğümlerin 
adreslerine dikkat edecek olursanız listedeki konumları değişse de hafızadaki konumları 
değişmemektedir.

Son olarak kullanıcı 3. Seçeneği seçerse SayilarListesi içerisindeki en büyük Sayi listeden 
çıkartılmalıdır.

Klasör Hiyerarşisi
o src Klasörü (Kaynak dosyalarınızın bulunduğu klasör)
o lib Klasörü (.o dosyalarının bulunduğu klasör)
o include Klasörü (Başlık dosyalarınızın bulunduğu klasör)
o doc Klasörü (Raporunuzun bulunduğu klasör.)
o bin Klasörü (Çalıştırılabilir dosyalarınızın (.exe) bulunduğu klasör.)
o benioku.txt (Program için ayrıca belirtmek istedikleriniz. Önerileriniz. Boş kalabilir.)
o makefile
