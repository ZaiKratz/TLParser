#include "../Public/UpdateShort.h"


//begin namespace block
namespace COMMON
{

UpdateShort::UpdateShort()
{
	this->_ConstructorID = 2027216577;
}

UpdateShort::UpdateShort(PRIVATE::Update*  update, FDateTime date)
{
	this->_ConstructorID = 2027216577;
	this->update = update;
	this->date = date;
}
void UpdateShort::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->update->OnSend(Writer);
	Writer.TGWriteDate(this->date);
}


void UpdateShort::OnResponce(BinaryReader& Reader)
{
	update = reinterpret_cast<PRIVATE::Update* >(Reader.TGReadObject());
	date = Reader.TGReadDate();
	this->_Responded = true;
}
UpdateShort::~UpdateShort()
{

}
}//end namespace block
