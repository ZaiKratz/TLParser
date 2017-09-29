#include "../Public/PageBlockAuthorDate.h"


//begin namespace block
namespace COMMON
{

PageBlockAuthorDate::PageBlockAuthorDate()
{
	this->_ConstructorID = -1162877472;
}

PageBlockAuthorDate::PageBlockAuthorDate(PRIVATE::RichText*  author, FDateTime published_date)
{
	this->_ConstructorID = -1162877472;
	this->author = author;
	this->published_date = published_date;
}
void PageBlockAuthorDate::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->author->OnSend(Writer);
	Writer.TGWriteDate(this->published_date);
}


void PageBlockAuthorDate::OnResponce(BinaryReader& Reader)
{
	author = reinterpret_cast<PRIVATE::RichText* >(Reader.TGReadObject());
	published_date = Reader.TGReadDate();
	this->_Responded = true;
}
PageBlockAuthorDate::~PageBlockAuthorDate()
{

}
}//end namespace block
