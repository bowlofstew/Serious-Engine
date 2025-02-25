/* Copyright (c) 2002-2012 Croteam Ltd. All rights reserved. */

#include "EntityHashing.h"
#include <Engine\Templates\HashTable.cpp>

extern FLOAT ser_fPositionTreshold;
extern FLOAT ser_fOrientationTreshold;



BOOL CEntityHashItem::ClientNeedsUpdate(INDEX iClient,CNetworkMessage &nmMessage)
{
  ASSERT (iClient>=0 && iClient<SERVER_CLIENTS);

  CClientEntry ceEntry = ehi_ceClientEntries[iClient];

  CPlacement3D &plPlacement = ehi_epEntityPointer->en_plPlacement;
  CPlacement3D &plLastPlacement = ceEntry.ce_plLastSentPlacement;

  FLOAT fPositionDelta,fOrientationDelta;

  fPositionDelta =   fabs(plLastPlacement.pl_PositionVector(1) - plPlacement.pl_PositionVector(1))
                   + fabs(plLastPlacement.pl_PositionVector(2) - plPlacement.pl_PositionVector(2)) 
                   + fabs(plLastPlacement.pl_PositionVector(3) - plPlacement.pl_PositionVector(3));
  fOrientationDelta =   fabs(plLastPlacement.pl_OrientationAngle(1) - plPlacement.pl_OrientationAngle(1))
                      + fabs(plLastPlacement.pl_OrientationAngle(2) - plPlacement.pl_OrientationAngle(2))
                      + fabs(plLastPlacement.pl_OrientationAngle(3) - plPlacement.pl_OrientationAngle(3));

  BOOL bSendNow = (fPositionDelta >= ser_fPositionTreshold) || (fOrientationDelta > ser_fOrientationTreshold);

  if (bSendNow) {
    WritePackedPlacement(ceEntry,nmMessage);
    return TRUE;
  }

  return FALSE;

};


void CEntityHashItem::WritePackedPlacement(CClientEntry &ceEntry,CNetworkMessage &nmMessage)
{
  CPlacement3D &plPlacement = ehi_epEntityPointer->en_plPlacement;
  CPlacement3D &plLastPlacement = ceEntry.ce_plLastSentPlacement;



};