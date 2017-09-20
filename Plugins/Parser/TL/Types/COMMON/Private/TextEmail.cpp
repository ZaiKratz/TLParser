#include "../Public/TextEmail.h"


//begin namespace block
namespace COMMON
{

TextEmail::TextEmail()
{
	this->_ConstructorID = -703767842;
}

TextEmail::TextEmail(PRIVATE::RichText* text, FString email)
{
	this->_ConstructorID = -703767842;
	this->text = text;
	this->email = email;
}
void TextEmail::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->text->OnSend(Writer);
	Writer.TGWriteString(this->email);
}


void TextEmail::OnResponce(BinaryReader& Reader)
{
	text = reinterpret_cast<PRIVATE::RichText*>(Reader.TGReadObject());
	email = Reader.TGReadString();
}
TextEmail::~TextEmail()
{

}
}//end namespace block
