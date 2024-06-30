use std::error::Error;

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
enum Menu {
    Rice,
    MisoSoup,
    Salad,
}

impl Menu {
    pub fn from_char(c: char) -> Option<Self> {
        match c {
            'R' => Some(Self::Rice),
            'M' => Some(Self::MisoSoup),
            'S' => Some(Self::Salad),
            _ => None,
        }
    }
}

#[derive(Default, Debug, Clone, Copy, PartialEq, Eq)]
enum FoldState {
    #[default]
    Default,
    ReadRice,
    ReadMisoSoupAfterRice,
}

impl FoldState {
    pub fn consume_menu(self, menu: Menu) -> Self {
        match self {
            Self::ReadMisoSoupAfterRice => self,
            Self::ReadRice => match menu {
                Menu::MisoSoup => Self::ReadMisoSoupAfterRice,
                _ => self,
            },
            Self::Default => match menu {
                Menu::Rice => Self::ReadRice,
                _ => Self::Default,
            },
        }
    }
}

fn main() -> Result<(), Box<dyn Error>> {
    let stdin = std::io::stdin();
    let line = {
        let mut buf = String::new();
        stdin.read_line(&mut buf)?;
        buf
    };
    let res = line
        .chars()
        .filter_map(Menu::from_char)
        .fold(FoldState::Default, |s, m| s.consume_menu(m));
    let res = match res {
        FoldState::ReadMisoSoupAfterRice => "Yes",
        _ => "No",
    };
    println!("{res}");
    Ok(())
}
