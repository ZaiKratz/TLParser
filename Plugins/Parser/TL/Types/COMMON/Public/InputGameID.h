#pragma once
#include "Engine.h"
#include "../../../Types/Private/InputGame.h"

#include "../../../Types/Private/InputGame.h"

//begin namespace block
namespace COMMON
{
class InputGameID : public PRIVATE::InputGame
{
public:
	InputGameID();
	InputGameID(unsigned long long id, unsigned long long access_hash);

	~InputGameID();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	unsigned long long id;
	 unsigned long long access_hash;
};
} //end namespace block
