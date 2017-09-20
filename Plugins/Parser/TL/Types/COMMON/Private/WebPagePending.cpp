#include "../Public/WebPagePending.h"


//begin namespace block
namespace COMMON
{

WebPagePending::WebPagePending()
{
	this->_ConstructorID = 484083397;
}

WebPagePending::WebPagePending(unsigned long long id, FDateTime date)
{
	this->_ConstructorID = 484083397;
	this->id = id;
	this->date = date;
}
void WebPagePending::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteLong(this->id);
	Writer.TGWriteDate(this->date);
}


void WebPagePending::OnResponce(BinaryReader& Reader)
{
	id = Reader.ReadLong();
	date = Reader.TGReadDate();
}
WebPagePending::~WebPagePending()
{

}
}//end namespace block