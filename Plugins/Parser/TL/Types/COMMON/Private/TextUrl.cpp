#include "../Public/TextUrl.h"


//begin namespace block
namespace COMMON
{

TextUrl::TextUrl()
{
	this->_ConstructorID = -1048303556;
}

TextUrl::TextUrl(PRIVATE::RichText* text, FString url, unsigned long long webpage_id)
{
	this->_ConstructorID = -1048303556;
	this->text = text;
	this->url = url;
	this->webpage_id = webpage_id;
}
void TextUrl::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->text->OnSend(Writer);
	Writer.TGWriteString(this->url);
	Writer.WriteLong(this->webpage_id);
}


void TextUrl::OnResponce(BinaryReader& Reader)
{
	text = reinterpret_cast<PRIVATE::RichText*>(Reader.TGReadObject());
	url = Reader.TGReadString();
	webpage_id = Reader.ReadLong();
}
TextUrl::~TextUrl()
{

}
}//end namespace block