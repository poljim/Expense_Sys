    /*
     * std = standard library
     * harcama tipleri
     * harcama miktarı
     * para türü ? (her seferinde bunu girmek gıcık olabilir)
     * harcama tarihi (kayıt tuttuğumuz için) (otomatik kaydedilir)
     * harcama IDsi (sort fln gerekiyor, getirirken de id ile
     getirmek daha mantıklı gibi) ama ürün silince yenisinin yeni id ile kaydı nasıl
     yapılabilir?

    kişi belli tarihlerde harcama yapacak onu tablo gibi kaydetmemiz gerek
    harcama türleri için enum mu? (??)


    yazdırırken ID kullanmaya gerek var mı? id sadece giriş sırasına göre yazdırmaya yarıyor gibi
(örneğin son 10 girdiyi yazdır demek istiyorsun) (car.getID>5)
    sortta vs. de gerek yok gibi
 */
#include "Expense.h"

Expense::Expense(const std::string category, double amount, std::chrono::year_month_day date) {
    //this->id = id;
    this->category = category;
    this->amount = amount;
    this->date = date;
    // can use this instead, after()
    //: id(id), category(category), amount(amount), date(date)
}

//int Expense::getID() {return this->id = id;} // böyle niye olmuyo? (constu çıkardıktan sonra)

// getter should not modify the value, that's why all of them are constant
//int Expense::getID() const {}
std::string Expense::getCategory() const {return category;}
double Expense::getAmount() const {return  amount;}
std::chrono::year_month_day Expense::getDate() const {
        return date;}

//setters for updating values
//void Expense::setID(int newID){id = newID;}
