#include "../Public/InputBotInlineMessageMediaGeo.h"


//begin namespace block
namespace COMMON
{

InputBotInlineMessageMediaGeo::InputBotInlineMessageMediaGeo()
{
	this->_ConstructorID = -190472735;
}

InputBotInlineMessageMediaGeo::InputBotInlineMessageMediaGeo(COMMON::InputGeoPoint*  geo_point, TLBaseObject*  reply_markup)
{
	this->_ConstructorID = -190472735;
	this->geo_point = geo_point;
	this->reply_markup = reply_markup;
}
void InputBotInlineMessageMediaGeo::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(reply_markup)
	{
		Flags |= (1 << 2);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	this->geo_point->OnSend(Writer);
	if(this->reply_markup)
	{
	this->reply_markup->OnSend(Writer);
	}
}


void InputBotInlineMessageMediaGeo::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	geo_point = reinterpret_cast<COMMON::InputGeoPoint* >(Reader.TGReadObject());
	if((Flags & (1 << 2)) != 0) 
	{
	reply_markup = reinterpret_cast<TLBaseObject* >(Reader.TGReadObject());
	}
	this->_Responded = true;
}
InputBotInlineMessageMediaGeo::~InputBotInlineMessageMediaGeo()
{
	if(this->geo_point)
	{
		delete this->geo_point;
	}
	if(this->reply_markup)
	{
		delete this->reply_markup;
	}
}
}//end namespace block
