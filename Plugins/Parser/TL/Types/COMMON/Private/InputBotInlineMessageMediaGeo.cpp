#include "../Public/InputBotInlineMessageMediaGeo.h"


//begin namespace block
namespace COMMON
{

InputBotInlineMessageMediaGeo::InputBotInlineMessageMediaGeo()
{
	this->_ConstructorID = -509762060;
}

InputBotInlineMessageMediaGeo::InputBotInlineMessageMediaGeo(COMMON::InputGeoPoint* geo_point, PRIVATE::ReplyMarkup* reply_markup)
{
	this->_ConstructorID = -509762060;
	this->geo_point = geo_point;
	this->reply_markup = reply_markup;
}
void InputBotInlineMessageMediaGeo::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(!reply_markup)
	{
		Flags |= (1 << 2);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	this->geo_point->OnSend(Writer);
	if(!this->reply_markup)
	{
	this->reply_markup->OnSend(Writer);
	}
}


void InputBotInlineMessageMediaGeo::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	geo_point = reinterpret_cast<COMMON::InputGeoPoint*>(Reader.TGReadObject());
	if((Flags & (1 << 2)) != 0) 
	{
	reply_markup = reinterpret_cast<PRIVATE::ReplyMarkup*>(Reader.TGReadObject());
	}
}
InputBotInlineMessageMediaGeo::~InputBotInlineMessageMediaGeo()
{

}
}//end namespace block