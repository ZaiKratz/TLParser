#include "../Public/AppUpdate.h"


//begin namespace block
namespace HELP
{

AppUpdate::AppUpdate()
{
	this->_ConstructorID = -1987579119;
}

AppUpdate::AppUpdate(int32 id, bool critical, FString url, FString text)
{
	this->_ConstructorID = -1987579119;
	this->id = id;
	this->critical = critical;
	this->url = url;
	this->text = text;
}
void AppUpdate::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->id);
	Writer.WriteBool(this->critical);
	Writer.TGWriteString(this->url);
	Writer.TGWriteString(this->text);
}


void AppUpdate::OnResponce(BinaryReader& Reader)
{
	id = Reader.ReadInt();
	critical = Reader.ReadBool();
	url = Reader.TGReadString();
	text = Reader.TGReadString();
	this->_Responded = true;
}
AppUpdate::~AppUpdate()
{

}
}//end namespace block
