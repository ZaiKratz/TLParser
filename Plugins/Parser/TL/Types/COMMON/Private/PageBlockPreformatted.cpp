#include "../Public/PageBlockPreformatted.h"


//begin namespace block
namespace COMMON
{

PageBlockPreformatted::PageBlockPreformatted()
{
	this->_ConstructorID = 1054437568;
}

PageBlockPreformatted::PageBlockPreformatted(PRIVATE::RichText* text, FString language)
{
	this->_ConstructorID = 1054437568;
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
	text = reinterpret_cast<PRIVATE::RichText*>(Reader.TGReadObject());
	language = Reader.TGReadString();
}
PageBlockPreformatted::~PageBlockPreformatted()
{

}
}//end namespace block
