#include "../Public/UpdateSavedGifs.h"


//begin namespace block
namespace COMMON
{

UpdateSavedGifs::UpdateSavedGifs()
{
	this->_ConstructorID = 506754451;
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
}
UpdateSavedGifs::~UpdateSavedGifs()
{

}
}//end namespace block
