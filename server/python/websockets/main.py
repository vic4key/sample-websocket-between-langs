# Note:
#   - Make server fully websocket
#   - All paths of `ws://127.0.0.1:1609/*` are handling by websocket

import asyncio
import websockets as ws

async def handler(ws, path):
    while True:
        try:
            if path == "/echo":
                print(f"WS Server '{path}'")
                data = await ws.recv()
                print(f"WS Client sent '{data}'")
                await ws.send(f"WS Server replied '{data}'")
            else: pass # handling other paths
        except Exception as e: # client disconnected or other reasons
            print("Exception:", e)
            break

if __name__ == "__main__":
    start_server = ws.serve(handler, "127.0.0.1", 1609)
    asyncio.get_event_loop().run_until_complete(start_server)
    asyncio.get_event_loop().run_forever()

# # python 3.7 or later

# async def main():
#     async with ws.serve(handler, "127.0.0.1", 1609):
#         await asyncio.Future()

# if __name__ == "__main__":
#     asyncio.run(main())