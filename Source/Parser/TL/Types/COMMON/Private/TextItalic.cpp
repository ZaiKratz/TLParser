#include "../Public/TextItalic.h"


//begin namespace block
namespace COMMON
{

TextItalic::TextItalic()
{
	this->_ConstructorID = -653089380;
}

TextItalic::TextItalic(TLBaseObject*  text)
{
	this->_ConstructorID = -653089380;
	this->text = text;
}
void TextItalic::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->text->OnSend(Writer);
}


void TextItalic::OnResponce(BinaryReader& Reader)
{
	text = reinterpret_cast<TLBaseObject* >(Reader.TGReadObject());
	this->_Responded = true;
}
TextItalic::~TextItalic()
{
	if(this->text)
	{
		delete this->text;
	}
}
}//end namespace block
