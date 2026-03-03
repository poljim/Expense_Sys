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

 */
#include "Expense.h"

    Expense::Expense(int id, const std::string category, double amount, std::chrono::year_month_day date) {
        this->id = id;
        this->category = category;
        this->amount = amount;
        this->date = date;
        // can use this instead too after()
        //: id(id), category(category), amount(amount), date(date)
    }

int Expense::getId() const {return id;}
std::string Expense::getCategory() const {return category;}
double Expense::getAmount() const {return  amount;}
std::chrono::year_month_day Expense::getDate() const {
        return date;
    }