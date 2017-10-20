#include "../Public/UpdateSavedGifs.h"


//begin namespace block
namespace COMMON
{

UpdateSavedGifs::UpdateSavedGifs()
{
	this->_ConstructorID = -1821035490;
}
void UpdateSavedGifs::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void UpdateSavedGifs::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
UpdateSavedGifs::~UpdateSavedGifs()
{
}
}//end namespace block
