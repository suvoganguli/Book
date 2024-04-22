function namefigs
% NAMEFIGS Name unnamed figures using concatenation of Y axis labels

for hfig = find(ishandle(1:100))
    fig = get(hfig);
    
    % if this figure is already named, skip it
    if fig.Name
        continue;
    end
    
    labels = [];
    children = fig.Children;
    
    % loop over children, which appear in reverse order of definition
    for ilabel = size(children,1):-1:1;
        label = get(get(children(ilabel),'YLabel'));
        labelstr = label.String;
        
        % tack on next label, if it is non-empty
        if labelstr
            % tack on separator after any existing labels
            if labels
                labels = [labels ' // '];
            end
            
            labels = [labels labelstr];
        end
    end

    set(hfig, 'Name', labels);
end