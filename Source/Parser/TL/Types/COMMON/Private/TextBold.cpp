#include "../Public/TextBold.h"


//begin namespace block
namespace COMMON
{

TextBold::TextBold()
{
	this->_ConstructorID = 1730456516;
}

TextBold::TextBold(TLBaseObject*  text)
{
	this->_ConstructorID = 1730456516;
	this->text = text;
}
void TextBold::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->text->OnSend(Writer);
}


void TextBold::OnResponce(BinaryReader& Reader)
{
	text = reinterpret_cast<TLBaseObject* >(Reader.TGReadObject());
	this->_Responded = true;
}
TextBold::~TextBold()
{
	if(this->text)
	{
		delete this->text;
	}
}
}//end namespace block
