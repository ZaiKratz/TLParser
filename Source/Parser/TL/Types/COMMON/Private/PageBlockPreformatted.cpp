#include "../Public/PageBlockPreformatted.h"


//begin namespace block
namespace COMMON
{

PageBlockPreformatted::PageBlockPreformatted()
{
	this->_ConstructorID = -1066346178;
}

PageBlockPreformatted::PageBlockPreformatted(TLBaseObject*  text, FString language)
{
	this->_ConstructorID = -1066346178;
	this->text = text;
	this->language = language;
}
void PageBlockPreformatted::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->text->OnSend(Writer);
	Writer.TGWriteString(this->language);
}


void PageBlockPreformatted::OnResponce(BinaryReader& Reader)
{
	text = reinterpret_cast<TLBaseObject* >(Reader.TGReadObject());
	language = Reader.TGReadString();
	this->_Responded = true;
}
PageBlockPreformatted::~PageBlockPreformatted()
{
	if(this->text)
	{
		delete this->text;
	}
}
}//end namespace block
